# custom-ciphers
Custom tools for basic ciphers.

All tools work only on english alphabet characters.

`ABCDEFGHIJKLMNOPQRSTUVWXYZ` and `abcdefghijklmnopqrstuvwxyz`

### Rot13
```Shell
rot13 STRING
```

### Caesar
```Shell
caesar -e NUMBER/KEY STRING
caesar -d NUMBER/KEY STRING
```
Bruteforce mode:
```Shell
caesar -b STRING
```

### Vigenère
- [x] Basic encrypt/decrypt
- [ ] Crack known length key
- [ ] Guess key length
- [ ] Kasiski
- [ ] Friedman
```Shell
vigenere -e KEY STRING
vigenere -d KEY STRING
```

[Vigenère matematika.cz](https://matematika.cz/vigenerova-sifra)
