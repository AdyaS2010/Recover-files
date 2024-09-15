# JPEG Recovery

## Description
This project is a JPEG recovery tool written in C. It reads a forensic image, identifies JPEG files based on their headers, and recovers them by writing the data to new files. The program is useful for recovering lost or deleted JPEG files from a disk image.

## Features
- Recover JPEG files from a forensic image
- Identify JPEG files based on their headers
- Write recovered JPEG files to new files

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Recover-files.git
   ```
2. Navigate to the project directory:
   ```bash
   cd recover
   ```
3. Compile the code:
   ```bash
   make recover
   ```

## Usage
1. Run the application:
   ```bash
   ./recover image
   ```
   Replace `image` with the path to the forensic image file.

## Example
```bash
$ ./recover card.raw
```

![image](https://github.com/user-attachments/assets/7446825f-ca73-4bb2-9754-d6da353d2f57)
*Command

![image](https://github.com/user-attachments/assets/4e5b81a6-77ac-4bd8-9a96-fb59d0fb0107)

![image](https://github.com/user-attachments/assets/815a235b-58d6-4e30-a711-c104273710ae)

*Recovers lost files!*

## Contributing
1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Make your changes and commit them:
   ```bash
   git commit -m 'Add some feature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a pull request.

## License
This project is not licensed under any License currently. 
