const React = require("react");

class BeastForm extends React.Component {
    constructor(props) {
        super(props);
        this.handleSubmit = this.handleSubmit.bind(this);
        this.beastToRelease = {}
    }

    handleSubmit(e) {
        e.preventDefault();
        unshackle(this.beastToRelease.value)
    }

    render() {
        return (
            <form id="beastForm" onSubmit={this.handleSubmit}>
                <input id="beastToRelease" type="input"/>
                <button id='submit' type="submit">btn</button>
            </form>
        );
    }
}