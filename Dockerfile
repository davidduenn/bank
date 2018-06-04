FROM centos

LABEL maintainer="David Duenn <davidduenn@gmail.com>"

RUN yum update -y
RUN yum install -y ack tree
RUN yum install -y gcc gcc-c++ gdb
RUN yum install -y git make
RUN yum install -y tmux vim

RUN cd /home/; git clone https://github.com/davidduenn/bank/
