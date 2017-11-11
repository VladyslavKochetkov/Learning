import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

class App extends Component {
  constructor(props){
    super(props);
    this.state={
      button1Text: "Button1",
      inputArray: [],
      inputValue: "",
      p1: 1,
    };

    this.handleButton1 = this.handleButton1.bind(this);
    this.handleInputChange = this.handleInputChange.bind(this);
    this.handleInputPushToArray = this.handleInputPushToArray.bind(this);
  }

  handleButton1(){
    this.setState({
      p1: this.state.p1 + 1
    })
  }

  handleInputPushToArray(){
    var ele = <div>{this.state.inputValue}</div>;
    var tempArray = this.state.inputArray;
    tempArray.push(ele);
    this.setState({
        inputArray: tempArray,
        inputValue: ""
    })
  }

  handleInputChange(e){
    if(e.key === "Enter"){
      this.handleInputPushToArray();
    }else{
      this.setState({
        inputValue: this.state.inputValue + e.key
      })
    }
  }

  render() {
    return (
      <div className="App">
        <span>
          <button id={"button1"} onClick={this.handleButton1} style={{"margin": "3px 15px"}}>{this.state.button1Text}</button>
          <input id={"input1"} onKeyPress={e => this.handleInputChange(e)} value={this.state.inputValue}></input>
        </span>
        <p id={"p1"}>{this.state.p1}</p>
        <p id={"p2"}>{this.state.inputValue}</p>
        <p>{this.state.inputArray}</p>
      </div>
    );
  }
}

export default App;
