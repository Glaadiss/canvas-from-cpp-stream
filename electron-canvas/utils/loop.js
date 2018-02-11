var loop = function(fn, fps) {
  fps = fps || 60;

  var now;
  var delta;
  var interval;
  var then = new Date().getTime();

  var frames;
  var oldtime = 0;

  return (function loop() {
    requestAnimationFrame(loop);

    interval = 1000 / (this.fps || fps);
    now = new Date().getTime();
    delta = now - then;

    if (delta > interval) {
      // update time stuffs
      then = now - (delta % interval);

      // call the fn
      // and pass current fps to it
      fn();
    }
  }());
};

module.exports = { loop };