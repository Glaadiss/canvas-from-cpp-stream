module.exports = class Animal {
  constructor({ name, type, x, y, action = null }, ctx, playgroundConnect) {
    this.playgroundConnect = playgroundConnect;
    this.name = name;
    this.type = type;
    this.x = x;
    this.y = y;
    this.directionX = 0;
    this.directionY = 0;
    this.stepX = 0;
    this.stepY = 0;
    this.action = action;
    this.ctx = ctx;
    this.actionLevel = 1;
    this.fps = 90;
  }

  move(dstX, dstY) {
    // this.log(dstX, dstY);
    this.action = "MOVE";
    this.directionX = dstX;
    this.directionY = dstY;
    this.stepX = (dstX - this.x) / this.fps;
    this.stepY = (dstY - this.y) / this.fps;
  }

  setAction(action) {
    this.action = action;
    this.actionLevel = 1;
  }

  clear() {
    this.setAction("CLEAR");
  }

  pee() {
    this.setAction("PEE");
  }

  superSpecial() {
    this.setAction("RABBIT");
  }

  isSpecialAction(action) {
    return this.action === action && this.actionLevel < 60;
  }

  makeSpecialAction(action) {
    this.actionLevel += 10 / this.fps;
    this.playgroundConnect[action](this.x, this.y, this.actionLevel);
  }

  specialActionLoop(action) {
    if (this.isSpecialAction(action)) this.makeSpecialAction(action);
  }

  shouldMoving() {
    return (
      this.action === "MOVE" &&
      Math.abs(this.directionX - this.x) > Math.abs(this.stepX) &&
      Math.abs(this.directionY - this.y) > Math.abs(this.stepY) // this.directionY !== this.y > this.stepY
    );
  }

  makeStep() {
    this.x += this.stepX;
    this.y += this.stepY;
  }

  log(x, y) {
    console.log(`Moving animal ${this.name} to new destination: x ${x} y ${y}`);
  }

  show() {
    if (this.shouldMoving()) this.makeStep();
    this.specialActionLoop("PEE");
    this.specialActionLoop("CLEAR");
    this.specialActionLoop("RABBIT");
    this.ctx.fillText(
      `${this.type} ${this.name} : ${actionsDesc.get(this.action)}`,
      this.x,
      this.y
    );
  }
};

actionsDesc = new Map([
  ["PEE", "peeing"],
  ["CLEAR", "repairing"],
  ["RABBIT", "pooping"],
  ["MOVE", "running"],
  ["THINK", "thinking"],
  [null, "sleeping"]
])