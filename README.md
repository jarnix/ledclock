# Requirements

- 1 Raspberry Pi, raspbian installed, an IP address for your Raspberry Pi (use your dhcp server)
- 1 Arduino Uno
- a led strip: [buy this one from adafruit](https://www.adafruit.com/product/2842)
- some patience if you have a cat and even more if you have more than one

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
        DocumentRoot /var/www/ledclock/html

        <Directory /var/www/ledclock/html>
                AllowOverride All
        </Directory>
        
        ErrorLog ${APACHE_LOG_DIR}/error.log
        CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```

# Usage

http://<ip of your raspberry>