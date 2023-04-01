### How to setup 
compile
```
sudo gcc -w -fno-stack-protector -o downloaded_malicious_piece_of_software.exe main.c   
```

add SUID bit
```
sudo chmod u+s downloaded_malicious_piece_of_software.exe    
```

run
```
python3 exploit.py
```

---

### Vulnerabilities
- [x] Buffer overflow into password check bypass
- [x] curl path hijack into privilege escalation (only with script, just testing...)

