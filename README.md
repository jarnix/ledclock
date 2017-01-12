# Requirements

- 1 Raspberry Pi, raspbian installed, an IP address for your Raspberry Pi (use your dhcp server)
- 1 Arduino Uno
- a led strip: [buy this one from adafruit](https://www.adafruit.com/product/2842)
- some patience if you have a cat and even more if you have more than one
- a structure (3d printed or something else)

# Installation
```
sudo apt-get install -y php5
sudo apt-get install -y git
sudo su -s /bin/bash www-data
cd /var/www
git clone https://github.com/jarnix/nofussframework.git
git clone https://github.com/jarnix/ledclock.git
sudo chown -R www-data.www-data ledclock
sudo a2enmod rewrite
sudo apt-get install -y php5-intl
sudo service apache2 restart
```

# Apache vhost config
```
<VirtualHost *:80>
        ServerAdmin webmaster@localhost
        DocumentRoot /var/www/ledclock/webapp/html

        <Directory /var/www/ledclock/webapp/html>
                AllowOverride All
        </Directory>
        
        ErrorLog ${APACHE_LOG_DIR}/error.log
        CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```

# Structure

I chose to use MDF since it's cheaper than 3d printing at this size.

*disque de masquage*

outer radius
16.6 cm

inner radius
12.8 cm

height
0.3 cm

==disque socle

outer radius
15.92 cm

inner radius
12.8 cm

height
1 cm

===
disque inférieur

outer radius
18.2 cm

inner radius
14.4 cm

height
1 cm


# Usage

http://<ip of your raspberry>