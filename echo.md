Reads the entire line until something like `&&` appears. 

`echo "Hello," world! && echo echo` gives:

    Hello, world!
    echo

`echo \"Hello,\" world! && echo echo` gives:

    "Hello", world!
    echo

<h2>Links:</h2>
https://linuxize.com/post/echo-command-in-linux-with-examples/