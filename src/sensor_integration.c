import pyttsx3  # text to speech
import datetime
import wikipedia
import webbrowser
import pywhatkit
import os
import pyjokes
import wolframalpha
import json  # for news
import requests  # for news
import time
from playsound import playsound
import datefinder
import winsound
import pygame
import time
import random
import requests
import speech_recognition as sr  # listen from microphone and convert it into another form
import googletrans 
from gtts import gTTS
import os
import goslate

gt= googletrans.Translator()

# --sets the voice
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
print(voices)
# print(voices[1].id)
engine.setProperty('voice', voices[1].id)


# sets the voice---#

# --function to speak
def speak(audio):
    engine.say(audio)
    engine.runAndWait()


# function to speak--#

# --function for wishing
def wishMe():
    hour = int(datetime.datetime.now().hour)
    if (hour >= 0 and hour < 12):
        speak("good morning...")

    elif (hour >= 12 and hour < 18):
        speak("Good afternoon...")
    else:
        speak("good evening...")
    assname = ("ted")

def wishMeh():
        hour = int(datetime.datetime.now().hour)
        if (hour >= 0 and hour < 12):
            speak("शुभ प्रभात।..")


        elif (hour >= 12 and hour < 18):
            speak("नमस्कार...")

        else:
            speak("सुसंध्या।..")

        assname = ("ted")


# function for wishing--#

# --function for setting the alarm

def alarm(text):
    DateTime = datefinder.find_dates(text)  # extracting the date and time
    for mat in DateTime:  # matching
        print(mat)
    string = str(mat)
    Time = string[11:]  # turncating the date
    print(Time)
    Hour = Time[:-6]
    Hour = int(Hour)
    minute = Time[3:-3]
    minute = int(minute)
    print(Hour)
    print(minute)
    while True:
        if Hour == datetime.datetime.now().hour:  # takes time from system and checks
            if minute == datetime.datetime.now().minute:
                print("alarm is running")
                playsound('C:\\Users\\Admin\\Desktop\\ece 3rd sem\\projects\\AI ROBOT\\.vscode\\audio.mp3', )

            if minute < datetime.datetime.now().minute:
                break


# function for setting the alarm--#

# --function for sending whatsapp message
def emergency():
    Hour = int(datetime.datetime.now().hour)
    minute1 = int(datetime.datetime.now().minute)
    minute1 = minute1 + 1
    speak("please say the message")
    string = takeCommand().lower()
    speak("sending your message")
    pywhatkit.sendwhatmsg('+91 7397438080',
                          string, Hour, minute1)


# function for sending whatsapp message--#

# -- game function
def game():
    pygame.init()
    white = (255, 255, 255)
    yellow = (255, 255, 102)
    black = (0, 0, 0)
    red = (213, 50, 80)
    green = (0, 255, 0)
    blue = (50, 153, 213)

    dis_width = 600
    dis_height = 400

    dis = pygame.display.set_mode((dis_width, dis_height))
    pygame.display.set_caption('Snake Game')

    clock = pygame.time.Clock()

    snake_block = 10
    snake_speed = 15

    font_style = pygame.font.SysFont("bahnschrift", 25)
    score_font = pygame.font.SysFont("comicsansms", 35)

    def Your_score(score):
        value = score_font.render("Your Score: " + str(score), True, yellow)
        dis.blit(value, [0, 0])

    def our_snake(snake_block, snake_list):
        for x in snake_list:
            pygame.draw.rect(dis, black, [x[0], x[1], snake_block, snake_block])

    def message(msg, color):
        mesg = font_style.render(msg, True, color)
        dis.blit(mesg, [dis_width / 6, dis_height / 3])

    def gameLoop():
        game_over = False
        game_close = False

        x1 = dis_width / 2
        y1 = dis_height / 2

        x1_change = 0
        y1_change = 0

        snake_List = []
        Length_of_snake = 1

        foodx = round(random.randrange(0, dis_width - snake_block) / 10.0) * 10.0
        foody = round(random.randrange(0, dis_height - snake_block) / 10.0) * 10.0

        while not game_over:

            while game_close == True:
                dis.fill(blue)
                message("You Lost! Press C-Play Again or Q-Quit", red)
                Your_score(Length_of_snake - 1)
                pygame.display.update()

                for event in pygame.event.get():
                    if event.type == pygame.KEYDOWN:
                        if event.key == pygame.K_q:
                            game_over = True
                            game_close = False
                        if event.key == pygame.K_c:
                            gameLoop()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    game_over = True
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_LEFT:
                        x1_change = -snake_block
                        y1_change = 0
                    elif event.key == pygame.K_RIGHT:
                        x1_change = snake_block
                        y1_change = 0
                    elif event.key == pygame.K_UP:
                        y1_change = -snake_block
                        x1_change = 0
                    elif event.key == pygame.K_DOWN:
                        y1_change = snake_block
                        x1_change = 0

            if x1 >= dis_width or x1 < 0 or y1 >= dis_height or y1 < 0:
                game_close = True
            x1 += x1_change
            y1 += y1_change
            dis.fill(blue)
            pygame.draw.rect(dis, green, [foodx, foody, snake_block, snake_block])
            snake_Head = []
            snake_Head.append(x1)
            snake_Head.append(y1)
            snake_List.append(snake_Head)
            if len(snake_List) > Length_of_snake:
                del snake_List[0]

            for x in snake_List[:-1]:
                if x == snake_Head:
                    game_close = True

            our_snake(snake_block, snake_List)
            Your_score(Length_of_snake - 1)

            pygame.display.update()

            if x1 == foodx and y1 == foody:
                foodx = round(random.randrange(0, dis_width - snake_block) / 10.0) * 10.0
                foody = round(random.randrange(0, dis_height - snake_block) / 10.0) * 10.0
                Length_of_snake += 1

            clock.tick(snake_speed)

        pygame.quit()
        # quit()

    gameLoop()


# game function--#

# speak("Hiii !! I am TED, Happy to be hear. How may I help you ?? ")

# --it takes microphone input from the user and returns string output
def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening.....")
        r.pause_threshold = 1  # it takes the sentance after 1 sec
        audio = r.record(source, duration=5)
        # audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(f"user said: {query}\n")

    except Exception as e:
        # print(e)
        print("say that again please...")
        return "None"
    return query


# it takes microphone input from the user and returns string output--#

def takeCommand1():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening.....")
        r.pause_threshold = 1  # it takes the sentance after 1 sec
        audio = r.record(source, duration=5)
        # audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print("please use teddy as the trigger key")
        print(f"user said: {query}\n")

    except Exception as e:
        # print(e)
        return "None"
    return query

def takeCommandh(): #main 
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("मैं सुन रहा हूँ..")
        r.pause_threshold = 1  # it takes the sentance after 1 sec
        audio = r.record(source, duration=5)
        # audio = r.listen(source)

    try:
        print("कृपया प्रतीक्षा करें...")
        queryh = r.recognize_google(audio, language='hi-in')
        print(f"आपने कहा: {queryh}\n")

    except Exception as e:
        # print(e)
        print("कृपया उसे फिर से कहें..")
        return "None"
    return queryh


# it takes microphone input from the user and returns string output--#



def TaskExecutionh():
    wishMeh()
    while True:
        queryh = takeCommandh()
        text = gt.translate(queryh)
        print(queryh)


        if 'विकिपीडिया' in queryh:
            speak("कृपया प्रतीक्षा करें.... ")
            queryh = queryh.replace("विकिपीडिय", " ")

            wikipedia.set_lang("hi")
            resultsh = wikipedia.summary(queryh, sentences=2)
            print("विकिपीडिया के अनुसार ")
            print(resultsh)  # prints the results
            speak(resultsh)

        elif 'समाचार' in queryh:  # https://newsapi.org/account is used to get the api key and the url... very important
            gs = goslate.Goslate()


            print("आज की खबर")

            resulth = requests.get(
                'http://newsapi.org/v2/top-headlines?country=in&apiKey=d6f56bf30ccf49db9c8dfbf64bf03208')
            resulth.content
            data = json.loads(resulth.content)
            data['articles'][0]['title']
            for i in range(5):
                newsh = data['articles'][i]['title']
                translatedText = gs.translate(newsh,'HI-in')
                print(translatedText)
                speak(translatedText)






def TaskExecution():
    wishMe()
    while True:
        
        query = takeCommand().lower()
        queryh = takeCommandh()

        # ---tasks to perform
        if 'wikipedia' in query:  # we should mention the word wikipedia for searching
            speak("searching wikipedia... ")
            query = query.replace("wikipedia", " ")
            results = wikipedia.summary(query, sentences=2)
            speak("According to wikipedia ")
            print(results)  # prints the results
            speak(results)

        elif 'open youtube' in query:
            webbrowser.open("https://youtube.com")
            speak("opening Youtube")


        #elif 'इंग्लिश' in queryh:
            #TaskExecution()

        elif 'open google' in query:
            webbrowser.open("https://google.com")
            speak("opening google")

        elif 'time' in query:
            strTime = datetime.datetime.now().strftime("%H:%H:%S")
            print(strTime)
            speak(f"the time is {strTime} ")

        elif 'moodle' in query:
            webbrowser.open("https://moodlecms.licet.ac.in/my/")
            speak("opening LICET moodle")

        elif 'play' in query:  # plays song in youtube
            song = query.replace('play', '')
            speak('playing ' + song)
            pywhatkit.playonyt(song)

        elif 'search' in query:  # searches everything in internet
            query = query.replace("search", "")
            webbrowser.open(query)
            speak("searching" + query)

        # api key for news = d6f56bf30ccf49db9c8dfbf64bf03208
        elif 'news' in query:  # https://newsapi.org/account is used to get the api key and the url... very important
            speak("Getting your today's news ")
            result = requests.get(
                'http://newsapi.org/v2/top-headlines?country=in&apiKey=d6f56bf30ccf49db9c8dfbf64bf03208')
            result.content
            data = json.loads(result.content)
            data['articles'][0]['title']
            for i in range(5):
                news = data['articles'][i]['title']
                print(news)
                speak(news)

        elif 'reminder' in query:  # still not working
            speak('what is the remainder')
            title = takeCommand()
            notification.notify(
                title="title",
                message=" hi ",
                timeout=5
            )

        elif 'alarm' in query:  # the command should be like set an alarm and say am or pm
            speak("setting your alarm")
            alarm(query)

        elif 'emergency' in query:
            emergency()

        elif 'i am bored' in query or 'game' in query:
            speak("opening a game ")
            game()

        elif 'weather' in query:
            api_address = 'http://api.openweathermap.org/data/2.5/weather?appid=98416c148014db9e979b3558bc4eaaa5&q='
            city = "chennai"
            url = api_address + city
            json_data = requests.get(url).json()
            format_add = json_data['weather'][0]['description']
            print(format_add)
            speak(format_add)
            # api.openweathermap.org/data/2.5/weather?q={city name}&appid={API key}



        # tasks to perform ---

        # --tasks based on system

        elif ' open Word' in query:
            path = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Microsoft Office 2013\\Word 2013"  # user path
            os.startfile(path)
            speak("opening word ")

        elif 'open notepad' in query:
            path = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Accessories\\notepad"
            os.startfile(path)
            speak("opening notepad")
            print()

        # tasks based on system---

        # ---general conversations
        assname = ("ted")
        if 'ted' in query:
            speak("yes sir i am listening...")

        elif 'what\'s your name' in query:
            speak("Did I forget to introduce myself ?")
            speak("i'm \"ted\". your personal Assistant")
            speak("hi")

        elif 'how are you' in query:
            speak("I am fine, Thank you")
            speak("How are you, Sir")

        elif 'fine' in query or "good" in query:
            speak("It's good to know that your fine")

        elif 'what can you do' in query:
            speak("you can say, what is the news today, play your favourite music, set a remainder, and much more !!! ")

        elif 'who are you' in query:
            speak(
                "i'm " + assname + " your personal assistant and I am here to to help you, get your things done and to entertain you")

        elif 'joke' in query:  # tells a joke
            speak(pyjokes.get_joke())

        elif 'kingston' in query:
            speak("kingston is a nice guy and i love him a lot")

        elif 'alexa' in query or 'ok google' in query or 'siri' in query:  # if other trigger word is used
            speak("I'm flattered, but that's not me. I am your personal Assistant. what can I do for you ??")
        elif 'nothing' in query:
            speak("Okay,I'll be here when you need me ")

        elif 'human being' in query:
            speak("I like connecting with people..")

        elif 'do you have feelings' in query:
            speak("I have lots of emotions. I feel excited when I learn something new ")

        elif 'do you get angry' in query:
            speak("Getting angry never helps me solve problems")

        elif ('boyfriend' in query or 'girlfriend' in query or 'relationship' in query):
            speak("I'm happy to say I feel whole all on my own")

        elif 'i love you' in query or 'do you love me' in query:
            speak("oh my dear......, thank you. I Love you tooo, Anything I can help you with")

        elif 'how old are you' in query or 'age' in query:
            speak("I was launched on 2021, so I'm fairly young ")

        elif 'Weather Today' in query:
            speak("")

        if 'donkey' in query or 'goodbye' in query:
            speak("going to sleep")
            break




        # general conversations---

        else:
            pass

    takeCommand()


if __name__ == "__main__":

    # speak("Hiii !! I am TED, Happy to be here. How may I help you ?? ")

    # --logic for executing task on query
    while True:

        query = takeCommand1().lower()

        if 'wake up' in query:
            TaskExecution()

        elif 'hindi' in query:
            TaskExecutionh()

        if 'quit' in query:
            break

        # ---tasks to perform
