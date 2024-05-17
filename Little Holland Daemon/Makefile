# Makefile for Little Holland Daemon

# Define the Python interpreter
PYTHON = python3

# Define the script and config
DAEMON_SCRIPT = daemon.py
CONFIG_FILE = config.json

# Default target
.PHONY: all
all: run

# Target to run the daemon
.PHONY: run
run:
	@echo "Running Little Holland Daemon..."
	$(PYTHON) $(DAEMON_SCRIPT)

# Target to install dependencies
.PHONY: install
install:
	@echo "Installing dependencies..."
	$(PYTHON) -m pip install -r requirements.txt

# Target to check the Python script for errors
.PHONY: lint
lint:
	@echo "Checking the Python script for errors..."
	$(PYTHON) -m pylint $(DAEMON_SCRIPT)

# Target to clean up
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf __pycache__

# Help target to display the usage
.PHONY: help
help:
	@echo "Makefile for Little Holland Daemon"
	@echo ""
	@echo "Usage:"
	@echo "  make           Run the default target (run)"
	@echo "  make run       Run the daemon"
	@echo "  make install   Install dependencies"
	@echo "  make lint      Check the Python script for errors"
	@echo "  make clean     Clean up"
	@echo "  make help      Display this help message"
	