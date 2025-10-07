const imgEl = document.getElementById('frame') as HTMLImageElement;
const fpsEl = document.getElementById('fps') as HTMLSpanElement;
const resEl = document.getElementById('res') as HTMLSpanElement;

let last = performance.now();
let frames = 0;

function updateStats() {
  frames++;
  const now = performance.now();
  if (now - last >= 1000) {
    fpsEl.textContent = String(frames);
    last = now;
    frames = 0;
  }
}

export function loadSample(base64Data: string) {
  imgEl.onload = () => {
    resEl.textContent = `${imgEl.naturalWidth}x${imgEl.naturalHeight}`;
  };
  imgEl.src = `data:image/png;base64,${base64Data}`;
}

setInterval(updateStats, 16);


