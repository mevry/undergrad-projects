export default {
    debug: true,
    state:{
        "FirstName":null,
        "LastName":null,
        "School":null,
        "Teacher":null,
        "JeopardyScore":null,
        "DragDropPass":null,
        "MemoryPass":null,
        "CompletedInfo":false
    },
    setFirst(firstName){
        this.state.FirstName = firstName
    },
    getFirst(){
        return this.state.FirstName
    }

}