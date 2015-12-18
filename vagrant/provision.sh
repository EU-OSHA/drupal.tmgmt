#!/bin/sh

# Potential fix to issue related to yum being stuck during provisioning
sudo sed -i 's/enabled=1/enabled=0/g' /etc/yum/pluginconf.d/fastestmirror.conf
sudo echo 'nameserver 8.8.8.8' > /etc/resolv.conf
sudo rm -f /var/cache/yum/timedhosts.txt
sudo yum makecache fast
sudo yum update -y

# MariaDB
sudo yum install mariadb-server mariadb -y
sudo systemctl enable mariadb
sudo cp /vagrant/etc/my.cnf.d/drupal.conf /etc/my.cnf.d/
sudo systemctl start mariadb
sudo mysql -u root -e "create database drupal"
sudo mysql -u root -e "GRANT ALL ON drupal.* TO drupal@'localhost' IDENTIFIED BY 'vagrant'"
sudo mysqladmin -u root password vagrant

# PHP
sudo rpm -Uvh https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
sudo rpm -Uvh https://mirror.webtatic.com/yum/el7/webtatic-release.rpm
sudo yum install -y php55w php55w-cli php55w-common php55w-gd php55w-intl php55w-ldap php55w-mbstring php55w-mcrypt php55w-mysql php55w-opcache php55w-pdo php55w-pear php55w-pecl-imagick php55w-pecl-memcached php55w-xml

# Increase the number of POST variables
echo "max_input_vars=20000" | sudo tee --append /etc/php.d/custom.ini
echo "date.timezone = 'Europe/Zurich'" | sudo tee --append /etc/php.d/custom.ini

# Drush
sudo yum install -y composer
sudo git clone https://www.github.com/drush-ops/drush /opt/drush
cd /opt/drush/ && sudo composer install
sudo ln -s /opt/drush/drush /usr/bin/drush
mkdir -p ~/.drush
cp /vagrant/etc/drushrc.php ~/.drush/

# Apache
sudo yum install -y httpd
sudo systemctl enable httpd
sudo setsebool -P httpd_can_sendmail on

sudo systemctl start httpd
sudo firewall-cmd --zone=public --add-port=80/tcp --permanent
sudo firewall-cmd --reload

sudo systemctl stop firewalld

# Optional - PHP uploadprogress (downloads ~ 60MB RPM - gcc, php55-devel)
# sudo yum install gcc php55w-devel
# sudo pecl install uploadprogress
# sudo echo "extension=uploadprogress.so" > etc/php.d/uploadprogress.ini

# Apache - fix the VH
sudo cp /vagrant/etc/httpd.conf /etc/httpd/conf/
sudo git clone https://github.com/EU-OSHA/drupal.tmgmt.git /var/www/html
sudo systemctl restart httpd

cd /var/www/html && ./install.sh

sudo chown -R vagrant:apache /var/www/html/
sudo chmod g+rwxs /var/www/html/docroot/sites/default/files/
sudo chmod -R g-w /var/www/html/docroot/sites/default/files/.htaccess

sudo chcon -R -t httpd_sys_rw_content_t /var/www/html/docroot/sites/default/files
sudo chcon -R -t httpd_sys_content_t /var/www/html/docroot/sites/default/settings.php
sudo chcon -R -t httpd_sys_content_t /var/www/html/docroot/sites/default/files/.htaccess

sudo yum clean all
echo "WARNING! All passwords are set to 'vagrant'. The vagrant account is insecure (password/key)!"


