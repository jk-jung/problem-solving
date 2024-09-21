export class Kata {
    static validatePin(pin: string): boolean {
        const regexp = new RegExp('^([0-9]{4}|[0-9]{6})$');
        return regexp.test(pin);
    }
}