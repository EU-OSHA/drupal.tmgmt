Vagrant VM for Drupal 7 stack
=============================

## Prerequisites

1. VirtualBox (tested with 5.x)
2. Vagrant (tested with 1.7.4)


## Installation

To create an virtual machine with a Drupal 7 working environment, type the following commands:

```
vagrant box add cristiroma/centos-7-minimal
vagrant plugin install vagrant-vbguest
vagrant plugin install vagrant-cachier
vagrant up
```

## Content

The VM will contain the full LAMP stack and a working Drupal installation

* MariaDB 5.5
* Apache 2.4
* PHP 5.5 (Webtatic)
* Drush 8.x-dev

## How to view the demo

After bootstrapping the VM, access the new instance by pointing your browser to http://localhost:8011

Note: If you look in the Vagrant file, port 80 is forwarded to port 8011 in the host.
