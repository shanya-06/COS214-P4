# COS214-P4
Cos 214 practical 4 repo

members: 
Shanya Nair - u25061845 
Ashley Mthemba - u25072235
Kendra Maree - u25070429

---

## Instructions for Marker

This project includes a Docker environment to ensure that all build and execution commands (including memory checks and debugging) can be reproduced exactly as intended, without requiring any project-specific dependencies installed on your host machine.

### 1. Build the Docker Image
To build the image and compile the project, run the following command from the root directory of the project:
```bash
docker build -t taskforge-env .
```

### 2. Run the Application
To execute the standard compiled program:
```bash
docker run --rm taskforge-env
```

### 3. Run Memory Diagnostics (Valgrind)
To verify that the application has zero memory leaks, you can override the default command to run Valgrind:
```bash
docker run --rm taskforge-env valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

### 4. Run Debugging (GDB)
To step through the application interactively using GDB, you must run the container in interactive mode with the appropriate privileges:
```bash
docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge-env gdb ./taskforge
```
*(Note: The `--cap-add=SYS_PTRACE` and `--security-opt` flags are explicitly required for GDB to attach to processes inside a Docker container).*
