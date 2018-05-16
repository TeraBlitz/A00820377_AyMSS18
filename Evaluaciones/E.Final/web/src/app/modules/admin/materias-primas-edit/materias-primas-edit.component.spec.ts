import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MateriasPrimasEditComponent } from './materias-primas-edit.component';

describe('MateriasPrimasEditComponent', () => {
  let component: MateriasPrimasEditComponent;
  let fixture: ComponentFixture<MateriasPrimasEditComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MateriasPrimasEditComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MateriasPrimasEditComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
