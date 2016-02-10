# EU-OSHA Translation management demo

This repository contains a fully working Drupal installation that demonstrates the functionality of the EU-OSHA translation management workflow. If you want to separately download only the Drupal module that implements the functionality, please use the `release` section of this repository where the archive is found.

[![Code Climate](https://codeclimate.com/github/EU-OSHA/drupal.tmgmt/badges/gpa.svg)](https://codeclimate.com/github/EU-OSHA/drupal.tmgmt)
[![Issue Count](https://codeclimate.com/github/EU-OSHA/drupal.tmgmt/badges/issue_count.svg)](https://codeclimate.com/github/EU-OSHA/drupal.tmgmt)

How to start using the product

* Read the [product specifications](docs/functional-specifications.pdf) located in the `docs/` directory.
* Create an working instance by using the Vagrant recipe located in the [vagrant](vagrant) directory.

## Known issues

In order to develop the product, we have integrated functionality from third party modules. However, during development we have identified issues using these modules, therefore we have applied a set of patches on these modules. To keep track of the applied patches, these are stored in the [patches](patches) directory.
