function createSecretHolder(x) {
    let t = x
    return {
        getSecret() {
            return t
        },
        setSecret(x) {
            t = x
        }
    }
}