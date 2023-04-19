# Capture the hack
## What is this "game"?
+ This exploit game aims to learn some very basic linux comands and also some low *hacking* knowlage to collect all flags.
+ And also this is project for BPC-IC1.
## How to play
### Initial setup:
+ compile
```bash
sudo gcc -w -g -fno-stack-protector -o downloaded_malicious_piece_of_software.exe main.c   
```
+ add SUID bit
```bash
sudo chmod u+s downloaded_malicious_piece_of_software.exe    
```
### Game tutorial:
> Main file to exploit is called ``exploit_this``. </br>
> The secret information is stored in ``cipher.txt``.
smthn smthn add later</br>

## BPC-IC1 things:

### Vulnerabilities
- [x] Buffer overflow into password check bypass
- [x] curl path hijack into privilege escalation (only with script, just testing...)