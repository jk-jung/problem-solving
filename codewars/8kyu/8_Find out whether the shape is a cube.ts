export function cubeChecker(volume: number, side: number): boolean{
    return side > 0 && side ** 3 == volume;
}