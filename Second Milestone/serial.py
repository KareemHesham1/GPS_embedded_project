import serial
import csv

# Define the port where your TM4C123GH6PM is connected
port = 'COM3'  # Replace 'COM3' with the port number you found in the device manager

# Define serial port settings
ser = serial.Serial('COM3', 9600)
# Open a CSV file in write mode
with open('serial_data.csv', 'w', newline='') as csv_file:
    csv_writer = csv.writer(csv_file)
    csv_writer.writerow(['lat', 'long'])  # Write header to CSV file

    try:
        
        while True:
            # Wait for the user to press "U"
           
            
                # Read a line of data from the serial port
                line = ser.readline().decode('utf-8').strip()
                
                # Split the received data into two parts (assuming data is separated by a comma)
                data_parts = line.split(',')
                
                # Write the received data to the CSV file in two columns
                csv_writer.writerow(data_parts)
                print("Data saved to serial_data.csv")
            
    except KeyboardInterrupt:
        # Close the serial port when Ctrl+C is pressed
        print("Serial port closed.")
        
ser.close()


