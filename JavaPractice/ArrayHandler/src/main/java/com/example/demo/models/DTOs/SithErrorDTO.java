package com.example.demo.models.DTOs;

public class SithErrorDTO implements ResponseDTO {

    private String sithMessage;

    public SithErrorDTO() {
    }

    public SithErrorDTO(String sithMessage) {
        this.sithMessage = sithMessage;
    }

    public String getSithMessage() {
        return sithMessage;
    }

    public void setSithMessage(String sithMessage) {
        this.sithMessage = sithMessage;
    }
}
