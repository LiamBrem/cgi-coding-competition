FROM python:3.11-slim

# Install C++ compiler for grader
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

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
