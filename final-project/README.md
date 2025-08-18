
# Electro.dr

#### Video Demo:https://youtu.be/PCNMzk50v1I
#### Description:
My project is an electronic device repair booking web application. In this application, a user can view which products are available for repair and then they need to log in as a user to make an order. If they are new users, they need to sign up first.

Then after the login, they are going to see their user page which shows their order details, if a user can place an order using the book service button it redirects them to the order page. Then their order is shown on the user page with order details and the current state of the order.

On the admin page admin can view all orders, and locations and update every order’s device status.

Let's look at every file one by one
(I used some code for my templates inspired by the CS50 finance problem.)

**App.py**

Here I understood and used all libraries and setups inspired by CS50's finance project.
Then I defined two lists.

***apology Function***

To handle and display error messages. Optionally passes additional data to the rendered template.

***login_required Decorator***

Ensures that only authenticated users can access a specific route.

***admin_required Decorator***

Ensures that only users with an "admin" role can access certain routes.

***Flask Route Function (index)***

It renders the index.html template.



***Flask Route Function (Signup)***

At first clears any existing session data.

*GET Requests:* Renders the signup.html template.

*POST Requests:*

Check if all required fields are provided and verify that the password matches the confirmation. If validation fails, an apology is flashed with an error message. Then Hash the password using generate_password_hash for security purposes. After that Inserts the new user's data (username, hashed password, role) into the users table, If the username already exists, an error is flashed. The new user's ID and role are stored in the session. After successful registration, redirect the user to the /admin route.

***Flask Route Function (Login)***

Clears any existing session data at the start.

*GET Requests:* Renders the login.html template.

*POST Requests:*

Check if all required fields are not empty. Queries the users table to retrieve the user record matching the submitted username, Validates the password using check_password_hash. Then store the user ID and role in the session for upcoming purposes. After successful login, the user is redirected to the /admin route.

***Flask Route Function (Admin)***

Ensures only logged-in admins can access this route. (@login_required, @admin_required)

*GET Requests:*

GET Request Retrieves all orders from the database, ordered by user ID. Renders the admin.html template with the orders and a predefined list of statuses.

*POST Requests:*

Ensure the status is field else redirect to the same route. Processes Updates the status of the specified order in the database.  After updating refresh the admin page to reflect the changes.



***Flask Route Function (users)***

@login_required Ensures only logged-in users can access the route.

*GET Requests:*
Receives all orders from the orders table associated with the logged-in user's ID (stored in session["user_id"]). Passes the retrieved orders to the users.html template for rendering.



***Flask Route Function (order)***

This route supports both GET and POST methods

*GET Requests:*Rendering the order.html template with the list of available devices.


*POST Requests:*

It ensures that a device is selected and verifies the user selected a location submission method (link or coordinates). If the user selects the location method as a Google Maps link, validate and use the provided Google Maps link. or the User selects the coordinates, then Construct a Google Maps query URL using the provided latitude and longitude. After that Save the order to the orders table with the above data, user_id(from the current session) and default status. Upon successful booking, the user is redirected to /users.

***Flask Route Function (change_pasword)***

First, it ensures the user is logged in(@login_required).

*GET Requests:* Rendering the change_password.html template.


*POST Requests:*

Ensures all required fields are provided. Checks if the new password matches the confirmation field. Then retrieves the current hashed password for the logged-in user and checks if the provided old password is correct. Hashes the new password and updates it in the database.Then redirects the user to the home page.

***Flask Route Function (logout)***

It clears any existing session data. Redirects the user to the home page.



**Layout.html**

This is the layout for my all pages. In the head, I was adding Bootstrap Integration, Custom Styles links and Dynamic Title with Jinja. It has a dark responsive navigation bar styled with Bootstrap and (a navbar-toggler) for small screens. The navbar has a brand name(styled with CSS) and some dynamic links.

A user who does not log in shows links like login and signup. If a user is logged in, it shows links like Home, Admin/User Dashboard, Change Password and Log Out. It also checks whether the user is an admin user or an ordinary user and shows the appropriate link in the navbar. Displays a Bootstrap alert bar for flash messages via Flask’s get_flashed_messages().

**index.html**

In the main content block, if the user is not logged in (if not session["user_id"]), a prompt appears to log in. A grid layout shows repairable devices using Bootstrap's card components. Bootstrap classes to ensure the layout adapts to various screen sizes.

**signup.html**

The main content block contains 3 form fields. Bootstrap classes (form-control, mx-auto, w-auto) are used for cantering and styling inputs. The form sends data to the /signup route via the POST method when the "Signup" button is clicked.

**log in.html**

The main content block contains 2 form fields. Form sent the data to the /login route via the POST method upon clicking the "Log In" button. I use the above same bootstrap class for this form also.

**Admin.html**

The main content block displays the admin dashboard with a table of all orders(order details). Admins can update the status of a specific order. And Jinja for loop to dynamically populate orders with data from the database and statuses for the dropdown menu.

**User.html**

The main content block, the user orders Table Displays all orders(details) made by the user and  Loops through orders using Jinja to populate rows.

**Order.html**

The order.html Main Content Block Contains the service booking form and location detection logic. Uses the navigator.geolocation API to retrieve the user's latitude and longitude. In the booking form, there is a dropdown for selecting a device to repair. Dynamically populated with devices list passed from the backend. Two methods are provided for location  Submission input, user can choose one of them. Then click the Submit Button it’s Submit the form to the /order route.

**Change_password.html**

The Main Content Block Contains the password change form. Then click the Chang_password Button, it’s Submit the form to the /change_password route.

**Styles.css**

This  CSS stylesheet includes custom styles for navigation bar branding, background color, and specific text styling.

**electro_dr.db**

This database contains the users and orders tables to store the information.

