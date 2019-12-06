package com.example.demo.models.DTOs;

public class TranslatorResponseDTO {
    private String translated;
    private String lang;

    public TranslatorResponseDTO(String translated, String lang) {
        this.translated = translated;
        this.lang = lang;
    }

    public TranslatorResponseDTO() {
    }

    public String getTranslated() {
        return translated;
    }

    public void setTranslated(String translated) {
        this.translated = translated;
    }

    public String getLang() {
        return lang;
    }

    public void setLang(String lang) {
        this.lang = lang;
    }
}
