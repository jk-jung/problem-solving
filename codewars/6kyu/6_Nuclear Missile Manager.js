function launchAll(launchMissile) {
    for (let i = 0; i < 5; i++) {
        setTimeout(() => launchMissile(i), i * 1000);
    }
}