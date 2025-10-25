# Use official OpenJDK base image
FROM openjdk:17-jdk-slim

# Set working directory
WORKDIR /app/java-app

# Copy Java source file into the container
COPY Greeter.java .

# Compile the Java program
RUN javac Greeter.java

# Expose port (optional — not needed for simple console apps)
EXPOSE 8080

# Run the compiled Java program
CMD ["java", "Greeter"]

