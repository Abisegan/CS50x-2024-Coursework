import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stocks_det =  db.execute("SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol HAVING shares > 0", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    total = cash
    for stock in stocks_det:
        stock_ud = lookup(stock["symbol"])
        stock["price"] = stock_ud["price"]
        stock["price_tot"] = stock_ud["price"] * stock["shares"]
        total += stock["price_tot"]

    return render_template("index.html", stocks_det = stocks_det, cash = cash, total = total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 400)

        quote_det = lookup(symbol)

        if quote_det == None:
            return apology("symbol does not exist", 400)

        get_shares = request.form.get("shares")
        if not get_shares:
            return apology("must provide share count", 400)
        shares = int(get_shares)
        if shares <= 0:
            return apology("input is not a positive integer", 400)

        total_amount = shares * quote_det["price"]

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        if cash < total_amount:
            return apology("cannot afford the number of shares at the current price", 400)


        new_cash = cash - total_amount

        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session["user_id"])
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, transaction_type) VALUES (?, ?, ?, ?, 'buy')", session["user_id"], quote_det["symbol"], shares, quote_det["price"])
        return redirect("/")


    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ? ", session["user_id"])
    return render_template("history.html", transactions = transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash( rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)

        stock_det = lookup(request.form.get("symbol"))
        if stock_det == None:
            return apology("symbol does not exist", 400)

        return render_template("quoted.html", name = stock_det["name"], price = stock_det["price"], symbol = stock_det["symbol"])


    else:
        return render_template("quote.html")




@app.route("/register", methods=["GET", "POST"])
def register():
    session.clear()
    """Register user"""
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation", 400)


        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password do not match", 400)


        hash = generate_password_hash(request.form.get("password"))
        try:
            register = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get("username"), hash)

        except:
            return apology("username already exists", 400)


        session["user_id"] = register
        return redirect("/")
    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    can't check until a frown turns upside down

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]


        new_cash = cash + total_amount

        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session["user_id"])
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, transaction_type) VALUES (?, ?, ?, ?, 'sell')", session["user_id"], quote_det["symbol"], shares * (-1), quote_det["price"])
        return redirect("/")


    else:
        symbols_ava = db.execute("SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", session["user_id"])
        return render_template("sell.html", symbols = symbols_ava)


@app.route("/change_password", methods=["GET", "POST"])
@login_required
def change_password():
    """Change user password"""
    if request.method == "POST":
        # Ensure old password was submitted
        if not request.form.get("old_password"):
            return apology("must provide old_password", 400)

         # Ensure new password was submitted
        elif not request.form.get("new_password"):
            return apology("must provide new_password", 400)


        # Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation", 400)


        elif request.form.get("new_password") != request.form.get("confirmation"):
            return apology("password do not match", 400)
        # Query database for id
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

        # Ensure old password is correct
        if not check_password_hash( rows[0]["hash"], request.form.get("old_password")):
            return apology("invalid old password", 400)

        new_hash = generate_password_hash(request.form.get("new_password"))
        db.execute("UPDATE users SET hash = ? WHERE id = ?", new_hash, session["user_id"])
        return redirect("/")
    else:
        return render_template("change_password.html")
