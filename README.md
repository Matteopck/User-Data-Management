Description
This code is a simple command-line application written in C++ that allows users to sign up and log in to an account system. The application stores user information, including username, password, email, first name, and last name, in a text file named "UsernameDB.txt".

--Features
User registration: Users can create a new account by providing their first name, last name, username, password, and email address.
User login: Existing users can log in to the application by entering their username and password.
Username and password validation: The application checks for duplicate usernames during registration and verifies the entered username and password during login.
Account information display: After successful registration or login, the application displays the user's account information.

--Classes
The code defines a single class named Username_Password with the following member functions:
Creat_Username_Password(): Prompts the user to enter their first name, last name, username, password, and email address for account registration.
Login_Username_Password(): Prompts the user to enter their username and password for login.
Display_Account_Info(): Displays the user's account information (username and password).
Save_New_username_Password_To_File(): Saves the user's account information to the "UsernameDB.txt" file.
Check_Existing_Username(): Checks if the entered username already exists in the "UsernameDB.txt" file.
Check_Correct_Username(): Checks if the entered username matches an existing username in the "UsernameDB.txt" file.
Check_Correct_Password(): Checks if the entered password matches the password associated with the entered username in the "UsernameDB.txt" file.

--Functions
The code includes the following functions:
Login_Menu_display(): Displays the main menu options (sign up or log in).
SignUp_menu(): Handles the sign-up process by creating a new Username_Password object and calling the necessary member functions.
Signin_Menu(): Handles the login process by creating a new Username_Password object and calling the necessary member functions.

--How to Run
To run the application, compile the code using a C++ compiler and execute the resulting binary file. The application will display a menu with options to sign up or log in. Follow the prompts to create a new account or log in with an existing account.
Note: The application stores user information in a text file named "UsernameDB.txt" in the same directory as the executable file. If the file does not exist, it will be created automatically.
