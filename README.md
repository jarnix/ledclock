# requirements

- 1 Raspberry Pi, raspbian installed
- 1 arduino uno
- apache, php5, nofussframework
- PHP extension: PHP Direct IO
- an IP address for your Raspberry Pi
- some patience if you have a cat and even more if you have more than one

# installation
```
apt-get install -y php5
apt-get install -y git
cd /var/www
git clone https://github.com/jarnix/nofussframework.git
git clone https://github.com/jarnix/ledclock.git
chown -R www-data.www-data ledclock
a2enmod rewrite
apt-get install -y php5-intl
```

yoohoo