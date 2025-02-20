<?php
// ** MySQL 설정 ** //
// 환경 변수를 사용하여 데이터베이스 설정을 구성합니다.
define('DB_NAME', getenv('MYSQL_DATABASE'));
define('DB_USER', getenv('MYSQL_USER'));
define('DB_PASSWORD', getenv('MYSQL_PASSWORD'));
define('DB_HOST', getenv('WORDPRESS_DB_HOST'));
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

// 인증 키와 솔트 설정 (고유한 키로 대체)
define('AUTH_KEY',         '9wNf$L+N^Jk7$Z1w~YF3#G^8c2Q+H$R');
define('SECURE_AUTH_KEY',  'S9Fz&LP&P@1!H^4~dW#2X9N^C+Z$R*T');
define('LOGGED_IN_KEY',    '#W$X^Z@E!1T9+C*R&LQ3%N^8G2F+H$R');
define('NONCE_KEY',        'C2Q*H#W$X^9F+L&R2Z1!J@T~d5S#3%Q');
define('AUTH_SALT',        'N^C+Z$R*T@1!H^2Q$G3#9F*L&R8C&W$X');
define('SECURE_AUTH_SALT', '%N^8G2F+H$R#W$X^Z@E!1T9+C*R&LQ3');
define('LOGGED_IN_SALT',   '3#G^8c2Q+H$R9wNf$L+N^Jk7$Z1w~YF');
define('NONCE_SALT',       'YF3#G^8c2Q+H$R9wNf$L+N^Jk7$Z1w~');

// 테이블 접두사 설정
$table_prefix = 'wp_';

// 디버그 모드 설정
define('WP_DEBUG', false);

// 끝에 아래 줄을 추가
if ( !defined('ABSPATH') )
    define('ABSPATH', dirname(__FILE__) . '/');
require_once(ABSPATH . 'wp-settings.php');