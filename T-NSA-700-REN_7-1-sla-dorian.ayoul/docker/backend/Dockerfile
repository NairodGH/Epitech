# Use the 12.4 Debian image as the base
FROM debian:12.4

# Update packages and install SSH server, sudo, and Python
RUN apt-get update && \
    apt-get install -y openssh-server sudo python3 \
    && rm -rf /var/lib/apt/lists/*

# Create a new user for SSH access (change 'backenduser' and 'backendpassword' to your desired username and password)
RUN useradd -m backenduser && \
    echo "backenduser:test" | chpasswd

# Allow dbuser to use sudo without a password
RUN echo "backenduser ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/backenduser

# Create the SSH directory and generate SSH host keys
RUN mkdir /var/run/sshd && \
    ssh-keygen -A

# Start the SSH server
CMD ["/usr/sbin/sshd", "-D"]
