FROM python:3.11-slim

# Install C++ compiler for grader and Java JDK
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    default-jdk \
    && rm -rf /var/lib/apt/lists/*

# Verify Java installation
RUN java -version && javac -version

# Set working directory
WORKDIR /app

# Copy grader source and build
COPY grader/ ./grader/
RUN cd grader && make clean && CXX=g++ make

# Copy questions directory
COPY questions/ ./questions/

# Set up entry point
WORKDIR /app/grader
ENTRYPOINT ["./grader"]
CMD ["--question", "1", "--lang", "python"]
