

**# Emergency Help & Rescue Management System**

A console-based application designed to facilitate the management of emergency services and user interactions during crises. This system allows users to request help from various emergency services and provides an admin interface for monitoring and managing user requests.

## 📂 Repository Structure
```


## 📝 Description
The Emergency Help & Rescue Management System helps users organize their emergency requests in a terminal window. Each request stores:

- **Username** (string)
- **Password** (string)
- **Emergency Service** (string)
- **Location** (string)
- **Contact Number** (string)
- **Issue Description** (string)
- **Request Status** (pending/completed)

All changes are saved to `users.txt` and `info.txt`, ensuring that user data persists between runs.

## ⚙️ Requirements
- A C compiler (e.g., `gcc`)
- Terminal / Command Prompt
- (Optional) `make` if you prefer using a Makefile

## 🚀 Usage
### Running the Executable
1. **Windows**: Compile and run in Command Prompt:
   ```bash
   gcc main.c user.c admin.c services.c utils.c -o emergency_rescue
   emergency_rescue.exe
   ```

2. **Linux / macOS**:
   ```bash
   gcc main.c user.c admin.c services.c utils.c -o emergency_rescue
   ./emergency_rescue
   ```

### Basic Workflow
1. **Sign Up**: Users can create an account with a username and password.
2. **Login**: Users log in to access their dashboard.
3. **View Emergency Services**: Users can view a list of available emergency services along with their contact information.
4. **Request Emergency Help**: Users select a service, provide their location and contact details, and describe their emergency issue.
5. **User  Dashboard**: Users can monitor their requests and view the status of their alerts.
6. **Logout**: Users can log out of the system.

### Notes
- If `users.txt` does not exist, it will be created automatically on the first sign-up.
- The system operates in a command-line interface (CLI) only.

## 🌟 Features
- **User  Functionalities**:
  - Registration and login
  - View emergency services
  - Request emergency help
  - User dashboard for monitoring requests

- **Admin Functionalities**:
  - Admin login
  - View all registered users
  - Monitor and manage emergency requests

## 🤝 Contributing
Feel free to fork this repository, make improvements (such as integrating real-time services, adding a GUI, etc.), and submit a pull request!

## 📜 Limitations
- The system does not integrate with real-time emergency services or GPS tracking.
- The platform operates in a command-line interface (CLI) only, lacking a graphical user interface (GUI).

## 🛠️ Topics Covered
- Modular programming in C
- Structures for User and Emergency Service
- Loops, conditionals, and arrays
- Function pointers and switch-case logic
- Basic input/output operations
- Menu-driven interface design

## ✅ Advantages
- Simplified user experience for requesting help
- Direct interaction with emergency services
- Admin oversight for monitoring requests
- Structured data handling for maintainability
- Real-time tracking of emergency requests
```

### Instructions for Use
1. Copy the above template into a file named `README.md` in your project directory.
2. Modify any sections as necessary to better fit your project specifics.
3. Save the file and commit it to your GitHub repository.

This README file provides a comprehensive overview of your project, making it easier for others to understand its purpose, usage, and how to contribute.
