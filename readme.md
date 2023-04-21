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
> Main file to exploit is called ``exploit_this``. </br>
> The secret information is stored in ``cipher.txt``.
smthn smthn add later</br>
star the program with ``./<whatever_name_you_picked>``
+ **First flag: buffer overflow**
	* After the program is started, player is asked for some password, well we dont know the password, se you need to find other way how to gain acces! </br>
	> hint:maybe try spam of ``A`` (somewhere between 1 and 50) ``1`` on the end? 


## BPC-IC1 things:

### Vulnerabilities
- [x] Buffer overflow into password check bypass
- [x] curl path hijack into privilege escalation (only with script, just testing...)

>! Spoiler text