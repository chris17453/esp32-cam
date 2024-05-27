# Camera Web Server Project

This project sets up a web server on an ESP32 device to handle camera captures and configuration management. The web server allows you to capture images, set secure keys, and upload configurations through HTTP requests. It uses the ESPAsyncWebServer library for handling web requests and responses.

## Features

- **Camera Configuration:** Configure the ESP32 camera with various frame sizes and settings.
- **Web Server:** Handle HTTP requests to capture images, update secure keys, and upload configurations.
- **Wi-Fi Connectivity:** Connect to a Wi-Fi network using credentials stored in a configuration file.
- **Debugging:** Print camera and system configurations for debugging purposes.

## Getting Started

### Prerequisites

- **Hardware:**
  - ESP32 with a camera module (e.g., AI Thinker, ESP-EYE).
  - SD card for storing configuration files.

- **Software:**
  - Arduino IDE with the following libraries:
    - `ESPAsyncWebServer`
    - `AsyncTCP`
    - `esp32-camera`

### Installation

1. **Clone the repository:**
   ```sh
   git clone https://github.com/your-repository/camera-web-server.git
   ```

2. **Install the required libraries:**
   - Open Arduino IDE.
   - Go to `Sketch > Include Library > Manage Libraries`.
   - Search for and install `ESPAsyncWebServer` and `AsyncTCP`.

3. **Prepare the configuration file:**
   - Create a file named `config.txt` on the SD card with the following content:
     ```
     ssid=your_ssid
     password=your_password
     device_name=your_device_name
     local_IP=192.168.1.100
     gateway=192.168.1.1
     subnet=255.255.255.0
     secure_key=your_secure_key
     resolution=QVGA
     heartbeat_server=your_server
     heartbeat_interval=60
     fqdn=your_fqdn
     debug=true
     ```

### Usage

1. **Upload the code:**
   - Open the project in Arduino IDE.
   - Select the appropriate board and port.
   - Upload the code to the ESP32.

2. **Insert the SD card:**
   - Insert the SD card with the `config.txt` file into the ESP32.

3. **Monitor the output:**
   - Open the Serial Monitor in Arduino IDE to view debug messages.
   - If the `debug` setting in the configuration file is `true`, the loaded configuration will be printed.

4. **Access the web server:**
   - Connect your computer to the same Wi-Fi network as the ESP32.
   - Open a web browser and navigate to the IP address specified in the configuration file (e.g., `http://192.168.1.100`).

### Endpoints

- **/capture:** Capture an image from the camera.
  - **Method:** POST
  - **Parameters:** `key` (required)
- **/setkey:** Set a new secure key.
  - **Method:** POST
  - **Parameters:** `new_key` (required)
- **/upload_config:** Upload a new configuration.
  - **Method:** POST
  - **Parameters:** `key` (required), `config` (required)

### Example

```bash
curl --max-time 0.3  -X POST http://192.168.1.122/capture -F "key=supersecretkey" --output example.jpg
```

![Example](./assets/example.jpg)

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the BSD 3 License. See the `LICENSE` file for details.

## Acknowledgements

- The ESPAsyncWebServer library for handling asynchronous web requests.
- The ESP32 camera library for camera support.