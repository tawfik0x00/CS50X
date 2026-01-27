from flask import Flask, render_template, request

# __name__ refer to the file name
app = Flask(__name__) # this is just a function we pass the application to it

# when we visit / as path we run index function to return a "hello, world"
@app.route("/", methods=["GET", "POST"])
def index():
    # this will return the file of the home page of our application
    # this read the file and return it
    # render_tmplate("Takes a files inside templates folder", parameter=value) and return its content
    # get is a dictionary method its return the values if the key if not found its return by default None
    # we can set the None or the second argument to any value
    # 405 method not allowed
    # route can teke list of methods its can be support
    # .route("path", methods=["GET", "POST"])

    # to check the method first
    if request.method == "POST":
        name = request.form.get("name", "world")
        return render_template("greet.html", name=name)
    return render_template("index.html")


