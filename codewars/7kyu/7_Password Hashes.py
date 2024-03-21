import hashlib
def pass_hash(str):
    string_bytes = str.encode('utf-8')

    md5_hash_obj = hashlib.md5()
    md5_hash_obj.update(string_bytes)

    hex_hash = md5_hash_obj.hexdigest()

    return hex_hash
