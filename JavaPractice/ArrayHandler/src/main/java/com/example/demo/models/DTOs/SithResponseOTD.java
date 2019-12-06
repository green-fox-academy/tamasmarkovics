package com.example.demo.models.DTOs;

public class SithResponseOTD implements ResponseDTO {
    private String sith_text;

    public SithResponseOTD() {
    }

    public SithResponseOTD(String sith_text) {
        this.sith_text = sith_text;
    }

    public String getSith_text() {
        return sith_text;
    }

    public void setSith_text(String sith_text) {
        this.sith_text = sith_text;
    }
}
