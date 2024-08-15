# docker run --rm -it -v gitlab-runner-config:/etc/gitlab-runner -v /var/run/docker.sock:/var/run/docker.sock gitlab/gitlab-runner:latest register --url https://gitlab.gabrielhamel.fr --token TOKEN HERE
# docker run --restart always -d -it -v gitlab-runner-config:/etc/gitlab-runner -v /var/run/docker.sock:/var/run/docker.sock --name gitlab-runner gitlab/gitlab-runner:latest
