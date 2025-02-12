# Password Manager 🔐  

A simple and secure command-line-based password manager built in C++. It allows users to securely manage their passwords locally. This project demonstrates essential C++ skills like file handling, encryption, and command-line interface design.

---

## Features ✨  
- **Secure Storage**: Encrypts and stores your passwords locally in a file.  
- **Master Password Protection**: Access to the password manager is secured with a master password.  
- **Command-Line Interface (CLI)**: Simple text-based menu for adding, viewing, and managing passwords.  
- **Cross-Platform Support**: Supports building and running on Windows, Linux, and macOS.

---

## Project Structure 📁  
```
.
├── main.cpp              # Entry point for the application
├── PasswordManager.cpp   # Core password management logic
├── PasswordManager.h     # Header file for PasswordManager
├── Makefile              # Build script for Unix-based systems
├── build.bat            # Build script for Windows
├── clean.bat            # Clean script for Windows
└── README.md             # Project documentation
```

---

## Build Instructions 🛠️

### For Unix-based Systems (Linux/macOS)
1. Ensure you have `g++` and `make` installed.  
   You can install `make` using your package manager (`apt`, `brew`, etc.).  
   
2. Open a terminal and navigate to the project directory.

3. Run the following commands:  
   - To build the project:
     ```sh
     make
     ```
   - To clean up the generated files:
     ```sh
     make clean
     ```

4. The executable `passwddotexe.exe` will be created.

---

### For Windows Systems
You can build and clean the project using `.bat` scripts:

1. **Build the Project**  
   Double-click or run `build.bat` in the terminal:
   ```sh
   build.bat
   ```

2. **Clean the Build**  
   To remove the executable, run `clean.bat`:
   ```sh
   clean.bat
   ```

---

## Usage 🚀  

Once the project is built, run the `passwddotexe.exe` file from the terminal:  
```sh
./passwddotexe.exe
```

### Example Workflow:
1. **Enter Master Password**: Authenticate with your master password.  
2. **Menu Options**:  
   - Add new passwords.  
   - View stored passwords.  
   - Delete existing passwords.  

---

## Future Enhancements 🌱
- Add a password generator feature.  
- Support for exporting/importing password databases.  
- Implement AES encryption for enhanced security.  

---

## Contributing 🤝  
Contributions are welcome! Feel free to open an issue or submit a pull request.  

---

## License 📜  
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contact 📬  
For any inquiries or suggestions, feel free to reach out or open an issue.
