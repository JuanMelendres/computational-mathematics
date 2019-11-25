# RSA CHAT
RSA (Rivest–Shamir–Adleman) is an algorithm used by modern computers to encrypt and decrypt messages. It is an asymmetric cryptographic algorithm. Asymmetric means that there are two different keys. This is also called public key cryptography, because one of the keys can be given to anyone. The other key must be kept private. The algorithm is based on the fact that finding the factors of a large composite number is difficult: when the integers are prime numbers, the problem is called prime factorization. It is also a key pair (public and private key) generator. 

RSA involves a public key and private key. The public key can be known to everyone; it is used to encrypt messages. Messages encrypted using the public key can only be decrypted with the private key. 

BUILD & RUN
===========

```
python serverclient.py server 8000 
python serverclient.py client 8000 
```

EXAMPLE
=======

Server:

```
Waiting for partner to join conversation...

Client connected:  127.0.0.1
Client's Public Key received
Public Key: (44377, 143)
Public Key sent
Type your message below and hit enter to send. Type 'EXIT' to end conversation.

hey
Message received:  hello
```

Client:

```
Public Key: (75655, 329)
Public key sent
Server's Public Key received
Connected to chat. Type your messages below and hit enter to send. Send 'EXIT' to leave the conversation.

Message received:  hey
hello
```
