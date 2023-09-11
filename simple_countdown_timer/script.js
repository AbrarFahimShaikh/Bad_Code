const eventDate = new Date("2023-12-31T00:00:00").getTime();

function formatTime(time) {
    return time < 10 ? `0${time}` : time;
}

const countdown = setInterval(function(){
    const currentDate = new Date().getTime()
    const timeLeft = eventDate - currentDate;

    if (timeLeft <= 0){
        clearInterval(countdown);
        document.getElementById("countdown").innerHTML = "Event has started!"
    }
    else{
        const days = Math.floor(timeLeft/(1000*60*60*24))
        const hours = Math.floor((timeLeft % (1000 * 60 * 60 * 24)) / (1000*60*60));
        const minutes = Math.floor((timeLeft % (1000*60*60)) / (1000*60))
        const seconds = Math.floor((timeLeft % (1000*60)) / 1000);

        document.getElementById("days").textContent = formatTime(days)
        document.getElementById("hours").textContent = formatTime(hours)
        document.getElementById("minutes").textContent = formatTime(minutes)
        document.getElementById("seconds").textContent = formatTime(seconds)
    }
}, 1000);
