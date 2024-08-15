FROM jenkins/jenkins:lts
WORKDIR /marvin
COPY . /marvin
COPY job_dsl.groovy /usr/share/jenkins/ref/init.groovy.d/job_dsl.groovy
COPY plugins.txt /usr/share/jenkins/ref/plugins.txt
RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt