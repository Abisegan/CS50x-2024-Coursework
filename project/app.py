from flask import Flask, render_template, redirect, flash, session, request
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from functools import wraps
from cs50 import SQL

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db = SQL("sqlite:///repair_shop.db")

STATUSES = [
    "We Will Reach You",
    "Pending",
    "In Progress",
    "Completed"
]

DEVICES = [
    "Phone",
    "Desktop Computer",
    "Laptop",
    "Tablet",
    "TV",
    "Kitchen Appliances"
]

def apology(template, message, code=400, list = None):
    if list is None:
        full_message = f"{message}. (Error{code})"
        flash(full_message)
        return render_template(template)
    else:
        full_message = f"{message}. (Error{code})"
        flash(full_message)
        return render_template(template, devices = list)

def login_required(f):

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)

    return decorated_function

def admin_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get('role') != 'admin':
            return redirect("/users")
        return f(*args, **kwargs)
    return decorated_function

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/signup", methods=["GET", "POST"])
def signup():
    session.clear()
    if request.method == "POST":
        username = request.form.get("username")
        if not username:
            return apology("signup.html", "must provide username", 467)

        password = request.form.get("password")
        if not password:
            return apology("signup.html", "must provide password", 400)

        if not request.form.get("confirmation"):
            return apology("signup.html.html", "must provide confirmation", 400)

        if password != request.form.get("confirmation"):
            return apology("signup.html", "password do not match", 400)

        hash = generate_password_hash(password)
        try:
            insert = db.execute("INSERT INTO users (username, hash, role) VALUES (?, ?, ?)",
                                  username, hash, 'user')

        except:
            return apology("signup.html", "username already exists", 400)

        user = db.execute("SELECT * FROM users WHERE id = ?", insert)[0]["role"]


        session["user_id"] = insert
        session["role"] = user
        return redirect("/admin")
    else:
        return render_template("signup.html")


@app.route("/login", methods=["GET", "POST"])
def login():

    session.clear()
    if request.method == "POST":

        username = request.form.get("username")
        if not username:
            return apology("login.html", "you must provide username", 403)

        password = request.form.get("password")
        if not password:
            return apology("login.html", "you must provide password", 403)

        user = db.execute("SELECT * FROM users WHERE username = ?", username)


        if len(user) != 1 or not check_password_hash(user[0]["hash"], password):
            return apology("login.html", "invalid username or password", 403)

        session["user_id"] = user[0]["id"]
        session["role"] = user[0]["role"]
        return redirect("/admin")
    else:
        return render_template("login.html")


@app.route("/admin", methods=["GET", "POST"])
@login_required
@admin_required
def admin():
    if request.method == "POST":
        status = request.form.get("status")
        if not status:
            return redirect("/admin")
        id = request.form.get("order_id")
        db.execute("UPDATE orders SET status = ? WHERE id = ?", status, id)


        return redirect("/admin")
    else:
        orders = db.execute("SELECT * FROM orders ORDER BY user_id")

        return render_template("/admin.html", statuses = STATUSES, orders = orders)

@app.route("/users")
@login_required
def users():

    orders = db.execute("SELECT * FROM orders WHERE user_id = ? ORDER BY id", session["user_id"])
    return render_template("/users.html", orders = orders)


@app.route("/order", methods=["GET", "POST"])
def order():
    if request.method == "POST":
        device = request.form.get("device")
        if not device:
            return apology("order.html", "you must select device", 403, DEVICES)
        location_met = request.form.get("location_met")
        location = None

        if not location_met:
            return apology("order.html", "you must select one location methode", 403, DEVICES)

        if location_met == "link":
            location = request.form.get("location")
            if not location:
                return apology("order.html", "you must provide location link", 403, DEVICES)

        elif location_met == "coordinates":
            latitude = request.form.get("latitude")
            longitude = request.form.get("longitude")
            if not (latitude or longitude):
                return apology("order.html", "you must provide location", 403, DEVICES)

            location = f"https://www.google.com/maps?q={f"{latitude},{longitude}"}"

        ini_status = STATUSES[0]
        db.execute("INSERT INTO orders (user_id, device, location, status) VALUES (?, ?, ?, ?)", session["user_id"], device, location, STATUSES[0])
        return redirect("/users")
    else:
        return render_template("/order.html", devices=DEVICES)

@app.route("/change_password", methods=["GET", "POST"])
@login_required
def change_password():
    if request.method == "POST":
        old_password = request.form.get("old_password")
        if not old_password:
            return apology("must provide old_password", 400)

        new_password = request.form.get("new_password")
        if not new_password:
            return apology("must provide new_password", 400)

        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("must provide confirmation", 400)

        if new_password != confirmation:
            return apology("password do not match", 400)

        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        hash = rows[0]["hash"]

        if not check_password_hash(hash, old_password):
            return apology("invalid old password", 400)

        new_hash = generate_password_hash(new_password)
        db.execute("UPDATE users SET hash = ? WHERE id = ?", new_hash, session["user_id"])
        return redirect("/")
    else:
        return render_template("change_password.html")




@app.route("/logout")
def logout():

    session.clear()

    return redirect("/")





if __name__ == "__main__":
    app.run(debug=True)
