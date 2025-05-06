#!/bin/bash
rm -rf /var/www/html/page404 /var/www/html/page500 /var/www/html/static-page
cp -R /page/* /var/www/html/
ls /page

echo "static page copy done"
