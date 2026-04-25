async function execute(action, nTimes) {
  let r = [];
  for (let i = 0; i < nTimes; i++) {
    let t = action();
    r.push(t);
  }
  for (let x of r) {
    await x;
  }
}
