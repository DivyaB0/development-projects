import time
from datetime import datetime as dt   #manipulates date and time.

# Local machine IP-This address is used to redirect blocked websites to the local machine, effectively preventing access.
ip_localmachine = "127.0.0.1"

# List of websites to block
website_list = ["www.facebook.com", "facebook.com", "www.instagram.com"]

# Path to the hosts file (Windows)
hosts_path = "C:\Windows\System32\drivers\etc\hosts"

# Define working hours (24-hour format)
start_time = "09:00:00"
end_time = "13:00:00" # working hours where the websites will be blocked

#This infinite loop ensures that the program continuously checks the current time and determines 
# whether to block or unblock websites based on the defined working hours.

while True:
    # Get the current time in HH:MM:SS format
    now = dt.now()
    current_time = now.strftime("%H:%M:%S")
    
    # If within working hours, block the websites
    #checks if the current time is within the defined working hours (09:00:00 to 12:00:00).
    if start_time <= current_time <= end_time:
        print("Working hours")
        with open(hosts_path, "r+") as file:
            content = file.read()
            for website in website_list:
                if website in content:
                    pass
                else:
                    file.write(ip_localmachine + " " + website + "\n")
                   
                    #If the current time is outside the working hours
    else:
        print("Non-working hours")
        with open(hosts_path, "r+") as file:
            content = file.readlines()
            file.seek(0)
            for line in content:
                if not any(website in line for website in website_list):
                    file.write(line)
            file.truncate()

    # Check every 10 seconds
    time.sleep(10)
