FROM node:18-alpine

WORKDIR /app

# Copy package.json and package-lock.json
COPY package.json package-lock.json ./

# Install dependencies
RUN npm install

# Copy the rest of the application files
COPY . .

# Build the project
RUN npm run build

# Expose the port for Azure
EXPOSE 80

# Set the environment variable for the port
ENV PORT 80

# Start the server
CMD ["npm", "run", "dev"]
