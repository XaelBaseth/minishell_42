<h2>BUILTINS</h2>

<h3>cd & pwd</h3>

cd ..

pwd

mkdir test

cd test

pwd

cd

pwd

cd un fichier fictif

<h3>echo</h3>

echo Hello

echo "Bonjour"

echo "B'onjou'r"

echo -n "Hello World!"

echo -nnnn "Hello"

echo - Hey

Echo Hey

echo Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse leo sapien, finibus ut nunc id, cursus sodales elit. Etiam tristique, felis ut gravida tempus, nunc lorem 

echo - "" "  " hello

<h3>env & unset & export</h3>

env

env hello world 

unset USER

env | grep USER

unset PATH

env | grep PATH

/bin/ls

export

export foo=42

export bar = school

export foo=hello

unset foo bar school

<h3>exit</h3>

exit 

exit 42

exit beaucoup de chiffre

<h2>SOME MORE TESTS</h2>

echo $?

doesntexist

echo $?

$EMPTY

echo $?

echo "hi" | cat | cat | cat | cat | cat | cat | cat

ps -a

ls |

export hello

env | grep hello

export | grep hello

<<<

<<'>

<<<<

echo hi |  < >>   |  |


<h2>SIGNAL TESTING</h2>

CTRL + D

oi + CTRL + D

CTRL + C

oi + CTRL + C

CTRL + \

<h2>REDIRECTIONS</h2>

cat << EOF
$>Hello
$>EOF

cat << EOF > input.txt
$>Hello $USER
$>This file is located in $PWD
$EOF

cat input.txt

cat << HERE >> input.txt
$> This is appended text!
$> HERE
$> So it doesn't overwrite new text!
$> DOC

cat input.txt

cat > input.txt

cat < input.txt