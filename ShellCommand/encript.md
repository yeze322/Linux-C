#md5
1. get md5 : ` md5sum filename > afile.file `
` check : md5sum -c afile.file ` (sha1sum also worked)
#other encription tools
1. list: `[md5, crypt, gpg, base64, sha1, openssl]`
2. md5sum and sha1sum is unsafe because of strong caculations ability. so use `sha512sum`instead

3. how to use :
- crypt PSWD <in>out / crypt PSWD <encripted>unlockname
- gpg -c filename / gpg filename.gpg
- base64 filename > encode / base64 -d encode > unlockfile