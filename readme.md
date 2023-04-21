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
sudo gcc -w -g -fno-stack-protector -o <whatever_name_you_want> main.c   
```
### Game tutorial:
Start the program with ``./<whatever_name_you_picked>``.
+ **First flag: Buffer overflow bypass the initial password check!**
	* After the program is started, player is asked for some password, well we dont know the password, se you need to find other way how to gain acces! <br>
	<details>
 	<summary>Hint here!</summary>

  ```
  Maybe try spam of ``A`` (somewhere between 1 and 35) ``1`` on the end?
  ```
	</details>
+ **Second flag:  Hijack the path for relative curl call in the program for shell and escalate privilege to root!**
	* ``$ strings exploit_this`` to get information about the compiled file. <br>
	* ``$ curl -I localhost`` - curl is calledwithout full path using $PATH variable! <br>
	* So you need to hijack the curl path and substitute curl for shell. <br>


## BPC-IC1 things:

### Vulnerabilities
- [x] Buffer overflow into password check bypass
- [x] curl path hijack into privilege escalation (only with script, just testing...)

