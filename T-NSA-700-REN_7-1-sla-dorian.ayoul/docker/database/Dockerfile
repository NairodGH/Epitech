# Use the 12.4 Debian image as the base
FROM debian:12.4

# Update packages and install SSH server, sudo, and Python
RUN apt-get update && \
    apt-get install -y openssh-server sshpass sudo python3 \
    && rm -rf /var/lib/apt/lists/*

# Create a new user for SSH access
RUN useradd -m dbuser && \
    echo "dbuser:test" | chpasswd

# Allow dbuser to use sudo without a password
RUN echo "dbuser ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/dbuser

# Create the SSH directory and generate SSH host keys
RUN mkdir /var/run/sshd && \
    ssh-keygen -A

# Start the SSH server
CMD ["/usr/sbin/sshd", "-D"]
